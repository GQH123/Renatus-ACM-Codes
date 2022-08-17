#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 320 
using namespace std;

struct Name{
	int l;
	char name[maxn];
	Name(){l = 0; memset(name, 0, sizeof(name));}
	Name(char* x){
		l = strlen(x);
		srep(i, 0, l) name[i] = x[i]; name[l] = '\0';
	}
	bool operator < (const Name b) const{
		if (l != b.l) return l < b.l;
		srep(i, 0, l) if (name[i] != b.name[i]) return name[i] < b.name[i];
		return false;
	}
};
struct Value{
	bool type; // 0 = int, 1 = string
	int l;
	char value[maxn];
	Value(){l = type = 0; memset(value, 0, sizeof(value));}
	Value(bool _type, char* x){
		type = _type;
		if (!type){
			l = strlen(x);
			srep(i, 0, l) value[i] = x[i]; value[l] = '\0';
		}
		else {
			l = strlen(x) - 2;
			srep(i, 0, l) value[i] = x[i + 1]; value[l] = '\0';
		} 
	}
	bool operator < (const Value b) const{
		if (type != b.type) return type < b.type;
		if (l != b.l) return l < b.l;
		srep(i, 0, l) if (value[i] != b.value[i]) return value[i] < b.value[i];
		return false;
	}
	void print(){
		printf("%s\n", value);
	}
	void dump(){
		if (!type) printf("integer: %s\n", value);
		else printf("string: \"%s\"\n", value); 
	}
};

map<Name, Value> lis;
bool on_err = 1;
int n;
char sta[4][maxn];
inline bool process(int cs){
	if (cs == 1) {
		if (!strcmp(sta[0], "Panic")) {
			printf("Script was KILLED.\n");
			return true;
		}
		else assert(false);
	}
	if (cs == 2) {
		if (!strcmp(sta[0], "Print")) {
			if (lis.count(Name(sta[1]))) lis[Name(sta[1])].print(); 
			else {
				if (sta[1][0] == '$') printf("NULL\n");
				else printf("%s\n", sta[1]);
				if (on_err) {
					if (sta[1][0] == '$') printf("NOTICE: Undefined Variable %s.\n", sta[1]);
					else printf("NOTICE: Undefined Constant %s.\n", sta[1]);
				}
			}
			return false;
		}
		if (!strcmp(sta[0], "Dump"))  {
			if (lis.count(Name(sta[1]))) lis[Name(sta[1])].dump(); 
			else {
				if (sta[1][0] == '$') printf("NULL\n");
				else printf("string: \"%s\"\n", sta[1]); 
				if (on_err) {
					if (sta[1][0] == '$') printf("NOTICE: Undefined Variable %s.\n", sta[1]);
					else printf("NOTICE: Undefined Constant %s.\n", sta[1]);
				}
			}
			return false;
		}
		if (!strcmp(sta[0], "Errmsg")){
			if (!strcmp(sta[1], "ON")) on_err = 1;
			else if (!strcmp(sta[1], "OFF")) on_err = 0;
			else assert(false);
			return false;
		}
	}
	if (cs == 3){
		if (strlen(sta[1]) != 1 || sta[1][0] != '=') assert(false);
		if (sta[0][0] == '$'){
			bool _type = (sta[2][0] == '"') ? 1 : 0;
			lis[Name(sta[0])] = Value(_type, sta[2]);
		}
		else {
			if (lis.count(Name(sta[0]))) {
				if (on_err) printf("WARNING: Constant %s Already Defined!\n", sta[0]);
			}
			else {
				bool _type = (sta[2][0] == '"') ? 1 : 0;
				lis[Name(sta[0])] = Value(_type, sta[2]);
			}
		}
		return false;
	}
}
int main(){ 
	char ch; int cs = 0;
	bool over = 0; 
	while (1){
		//cerr << "Line: " << line << ' ' << over << endl;
		cs = 0;
		while (1){
			while (scanf("%c", &ch) == 1 && (ch == ' ' || ch == '\t'));
			if (ch == '\n') {if (!over) over = process(cs); break;}
			if (ch == '"') {
				int l = 0;
				sta[cs][l++] = ch;
				while (scanf("%c", &ch) == 1 && ch != '"') sta[cs][l++] = ch;
				sta[cs][l++] = ch;
				sta[cs][l] = '\0';
				cs++;
			}
			else if (ch == '=') {
				int l = 0;
				sta[cs][l++] = ch, sta[cs][l] = '\0';
				cs++;  
			}
			else {
				int l = 0;
				sta[cs][l++] = ch;
				while (scanf("%c", &ch) == 1 && ch != ' ' && ch != '\n' && ch != '\t' & ch != '=') sta[cs][l++] = ch;
				sta[cs][l] = '\0';
				cs++;
				if (ch == '=') {
					l = 0;
					sta[cs][l++] = ch, sta[cs][l] = '\0';
					cs++;  
				}
				if (ch == '\n') {if (!over) over = process(cs); break;}
			}
		}
	} 
	return 0;
}

import java.math.BigDecimal; 

import java.math.RoundingMode; 

public class Solution {
	double eps = 1e-8; 
int n, m;
public class edge{
	int next, to;
	double times; 
	public edge(int _next, int _to, double _times){
		next = _next;
		to = _to;
		times = _times;
	}
};
edge[] e = new edge[200040];
int cnt = 1;
int[] h = new int[220];
int[] in = new int[220];
void Add_Edge(int x, int y, double times){
	e[++cnt] = new edge(h[x], y, times);
	h[x] = cnt; 
	in[y]++;
}
BigDecimal s;
BigDecimal[] val = new BigDecimal[220];
int[] _in = new int[220];
int[] lis = new int[220];
int head = 0, tail = 0;
void process(){
	for (int i = 1; i <= n; i++) {
		_in[i] = in[i];
		//System.out.println(in[i]);
		val[i] = new BigDecimal(0); 
	}
	head = tail = 0;
	lis[++head] = 1;
	val[1] = new BigDecimal(1.0); 
	while (head != tail){	
		int x = lis[++tail]; 
		//if (val[x] >= s - eps) return true;
		for (int i = h[x]; i != 0; i = e[i].next){
			int op = e[i].to;
			//System.out.println(e[i].times);
			val[op] = val[op].add((new BigDecimal(e[i].times)).multiply(val[x]));
			//if (val[op] >= s - eps) return true;
			_in[op]--;
			if (_in[op] == 0) lis[++head] = op;
		}
	}
	//cout << head << ' ' << tail << endl;
	//assert(head == n && tail == n);
	//return false;
}
/*
BigDecimal solve(BigDecimal l, BigDecimal r){
	int T = 200;
	while (T--){
		BigDecimal mid = (r + l) / 2.0;
		if (judge(mid)) r = mid;
		else l = mid;
	}
	return l;
}
*/
void recover(){
	for (int i = 1; i <= n; i++) h[i] = in[i] = 0; cnt = 1;
} 
    /**
     * @param n: the number of loudspeaker
     * @param minVolume: the minVolume the micro 
     * @param maxVolume: the maxVolume the micro 
     * @param edges: the edges
     * @param times: the times of edge
     * @param s: the volume you need
     * @return: return the min volume the micro need 
     */
    public double minMicro(int _n, int minVolume, int maxVolume, int[][] edges, double[] times, double _s) {
        n = _n;
        m = times.length;
        s = new BigDecimal(_s);
        for (int i = 0; i < m; i++){
        	int x = edges[i][0], y = edges[i][1];
        	Add_Edge(x, y, times[i]);
        }
        //BigDecimal res = solve(minVolume, maxVolume);
        process();
        //BigDecimal mx = 0;
        //for (int i = 1; i <= n; i++) mx = max(mx, val[i]); 
        //if (!judge(res)) {recover(); return -1;}
        //else {recover(); return res; }
        BigDecimal mx = new BigDecimal(0);
        for (int i = 1; i <= n; i++){
        	if (val[i].compareTo(mx) == 1) mx = val[i];
        	//System.out.println(val[i].doubleValue());
        }
        //System.out.println(mx.doubleValue());
        //System.out.println(s.doubleValue());
       	mx = s.divide(mx, 100, RoundingMode.HALF_UP);
       	//System.out.println(mx.doubleValue());
       	if (mx.compareTo(new BigDecimal(maxVolume)) == 1) return -1;
       	if ((new BigDecimal(minVolume)).compareTo(mx) == 1) return minVolume;
       	return mx.doubleValue();
    }
    public static void main(String args[]){
    	System.out.println(new Solution().minMicro(4, 1, 3, new int[][]{{1,2},{1,3},{2,3},{3,4},{1,4}}, new double[]{2.0,3.0,1.0,2.0,1.0}, 8.0));
    }
};

/*
int main(){ 
	cout << Solution().minMicro(4, 1, 3, {{1,2},{1,3},{2,3},{3,4},{1,4}}, {2.0,3.0,1.0,2.0,1.0}, 8.0) << endl;
	
	return 0;
}
*/


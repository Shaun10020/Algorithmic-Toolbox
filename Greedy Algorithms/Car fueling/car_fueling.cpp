#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int current_stop=0;
    int current_index=0;
    int refills=0;
    int current_ref=0;
    while (dist-current_stop>tank){
        current_ref=refills;
        for(int i=current_index;i<stops.size();i++){
            if(current_stop+tank-stops[i]<0){
                if (current_stop==stops[i-1])
                {
                    return -1;
                }
                else{
                current_stop=stops[i-1];
                current_index=i-1;
                refills++;
                break;}
            }
        }
        if (current_ref==refills){
            if (current_stop==stops[stops.size()-1]){
                return -1;
            }
            else{
            current_stop=stops[stops.size()-1];
            refills++;}
        }
    }
    return refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}

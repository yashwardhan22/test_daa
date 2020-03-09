#include<bits/stdc++.h>
using namespace std;

struct mystr{
    int mini;
    int maxi;
};

struct mystr getMinMax(int arr[], int low, int high) {
    struct mystr min_max, mml, mmr;
    int mid;
    if (low == high) {
        min_max.maxi = arr[low];
        min_max.mini = arr[low];
        return min_max;
    }
    if (high == low + 1) {
        if (arr[low] > arr[high]){
            min_max.maxi = arr[low];
            min_max.mini = arr[high];
        }
        else{
            min_max.maxi = arr[high];
            min_max.mini = arr[low];
        }
        return min_max;
    }

    mid = (low + high)/2;
    mml = getMinMax(arr, low, mid);
    mmr = getMinMax(arr, mid+1, high);

    if (mml.mini < mmr.mini) min_max.mini = mml.mini;
    else  min_max.mini = mmr.mini;

    if (mml.maxi > mmr.maxi)  min_max.maxi = mml.maxi;
    else min_max.maxi = mmr.maxi;

    return min_max;
}

int main(){
    int arr[] = {1000, 11, 445, 1, 330, 2030};
    int arr_size = 6;
    struct mystr min_max = getMinMax (arr, 0, arr_size-1);
    cout<<"\nMinimum element is "<<min_max.mini;
    cout<<"\nMaximum element is "<<min_max.maxi;
    getchar();
}

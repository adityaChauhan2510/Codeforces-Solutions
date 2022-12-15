/***
One fine day Govind thought of applying the Magic pair concept on Arrays.
Magic pair condition is something where we take a pair of numbers 
where this condition (j-i)!=arr[j]-arr[i] is satisfied.
Here j and i are indexes of array elements and arr[j] and arr[i] are array elements. Note that i<j.

Govind wants to find the total number of magic pairs present in the given array. 
Can you help govind to find the total number of pairs??


Example test case

Array: [4,1,3,3]

OutPut: 5

Explanation:

The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.

The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.

The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.

The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.

The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.

There are a total of 5 bad pairs, so we return 5.

***/

#include<iostream>
using namespace std;

#include<unordered_map>
int magicPairs(int arr[], int n){

    /*
    (j-i) != arr[j] - arr[i] this can be reformed as
    arr[i] - i != arr[j] - j . We need to find all pairs where this condition is satisfied.

    So we first find total number of pairs possible and then subtract the pairs which satisty
    arr[i] - i == arr[j] - j (i!=j)
    */

    // Insert to unordered map
    unordered_map<int , int> m;
    for(int i=0; i<n; i++){
        m[arr[i] - i]++;
    }

    int totalPairs = (n*(n-1))/2;
    int notMagicPairs = 0;

    //Iterate over map and find count all elements where arr[i] - i == arr[j] - j.
    //After that calculate the total number of pairs that can be formed using these elements.
    for(auto x : m){
        if(x.second != 1){
            notMagicPairs += ( x.second * (x.second-1))/2;
        }
    }

    return totalPairs - notMagicPairs;   //return number of magicPairs

}

int main(){
    int n;
    cin>>n;

    int *arr = new int[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

    
    cout << magicPairs(arr, n) <<endl;

    delete [] arr;
}
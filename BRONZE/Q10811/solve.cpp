#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void reverseBucket(vector<int> &buckets, int startBucket, int endBucket);

int main()
{
    int bucketNum, countM;
    int startBucket, endBucket;

    cin>>bucketNum>>countM;

    vector<int> buckets(bucketNum, 0);

    for(int i = 0; i < bucketNum; i++)
    {
        buckets[i] = i+1;
    }

    for(int i = 0; i < countM; i++)
    {
        cin>>startBucket>>endBucket;
        reverseBucket(buckets,startBucket,endBucket);
    }

    for(int i : buckets)
    {
        cout<<i<<' ';
    }

}

void reverseBucket(vector<int> &buckets, int startBucket, int endBucket)
{
    stack<int> stack;
    for(int i = startBucket-1; i <= endBucket-1; i++)
    {
        stack.push(buckets[i]);
    }
    for(int i = startBucket-1; i <= endBucket-1; i++)
    {
        buckets[i] = stack.top();
        stack.pop();
        
    }
}
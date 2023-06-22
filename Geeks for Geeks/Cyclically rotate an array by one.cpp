void rotate(int arr[], int n)
{
    reverse(arr,arr+n);
    reverse(arr,arr+1);
    reverse(arr+1,arr+n);
    
}

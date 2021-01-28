// Returns minimum number of jumps to reach arr[n-1] from arr[0] 
int minJumps(int arr[], int n) 
{ 
      
    // The number of jumps needed to reach the starting index is 0 
    if (n <= 1) 
        return 0; 
  
    // Return -1 if not possible to jump 
    if (arr[0] == 0) 
        return -1; 
  
    // initialization 
    int maxReach = arr[0];  // stores all time the maximal reachable index in the array. 
    int step = arr[0];      // stores the number of steps we can still take 
    int jump =1;//stores the number of jumps necessary to reach that maximal reachable position. 
  
    // Start traversing array 
    int i=1; 
    for (i = 1; i < n; i++) 
    { 
        // Check if we have reached the end of the array 
        if (i == n-1) 
            return jump; 
  
        // updating maxReach 
        maxReach = max(maxReach, i+arr[i]); 
  
        // we use a step to get to the current index 
        step--; 
  
        // If no further steps left 
        if (step == 0) 
        { 
            // we must have used a jump 
            jump++; 
  
            // Check if the current index/position or lesser index 
            // is the maximum reach point from the previous indexes 
            if(i >= maxReach) 
                return -1; 
  
            // re-initialize the steps to the amount 
            // of steps to reach maxReach from position i. 
            step = maxReach - i; 
        } 
    } 
  
    return -1; 
}




// method 2
int minJumps(int nums[], int n)
{
    vector<int> steps(n,-1);
    steps[0] = 0;
    int index_covered = 1;
    for(int i=0;i<n-1;i++){
        if(steps[i] == -1) continue;
        while(index_covered <= i+nums[i] && index_covered < n){
            steps[index_covered++] = steps[i] +1;
        }
    }
    return steps[n-1];
    
}

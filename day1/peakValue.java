package day1;



public class peakValue {
    

/*Complete the function below*/

class Solution
{
	// Function to find the peak element
	// arr[]: input array
	// n: size of array a[]
	public int peakElement(int[] arr,int n)
    {int low = 0;
        int high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Check if mid is a peak element
            if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid])) {
                return mid; // Found a peak element
            }
            // If the element on the left is greater, then there is a peak in the left half
            else if (mid > 0 && arr[mid - 1] > arr[mid]) {
                high = mid - 1;
            } 
            // If the element on the right is greater, then there is a peak in the right half
            else {
                low = mid + 1;
            }
        }
        
        return -1; // If no peak is found
       //add code here.
    }
}
}

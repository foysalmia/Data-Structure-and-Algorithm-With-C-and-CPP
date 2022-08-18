
# Stack Practise 
####  1. Given a stack with push(), pop(), and empty() operations, delete the middle of it without using any additional data structure. Note that, (n/2) + 1 th Element is the middle number.
#### Expected Time Complexity: O(n)

  
|SAMPLE | INPUT | OUTPUT | EXPLANATION |
|--|--|--|--|
|1| 5<br>1 2 3 4 5 | 1 2 4 5 | (5/2)+1=3rd element is deleted	|
|2| 6<br>1 2 3 4 5 6| 1 2 3 5 6| (6/2)+1=4th element is deleted|
  
#### 2. Given an array of elements, the task is to sort these elements using a stack.
#### Expected Time Complexity: O(n*n)
|SAMPLE | INPUT | OUTPUT |
|--|--|--|
|1| 7<br>8 5 7 1 9 12 10 | 1 5 7 8 9 10 12 |
|2| 8<br>7 4 10 20 2 5 9 1| 1 2 4 5 7 9 10 20|

#### 3. Given an array arr[] and a number k. The task is to delete k elements which are smaller than next element (i.e., we delete arr[i] if arr[i] < arr[i+1]) or become smaller than next because next element is deleted.
#### Expected Time Complexity: O(n^2)
|SAMPLE | INPUT | OUTPUT | EXPLANATION |
|--|----|--|------|
|1| 3<br>3 100 1<br>1 | 100 1 | arr[0] < arr[1] means 3 is less than 100, so delete 3. K is 1, thus 1 element deletion is completed.	|
|2| 5<br> 20 10 25 30 40 <br>2| 25 30 40| First we delete 10 because it follows arr[i] < arr[i+1]. Then we delete 20 because 25 is moved next to it and it also starts following the condition. K is 2, thus 2 element deletion is completed.|
  
### NB: All of this solutions are solved and foldered with the questions number.
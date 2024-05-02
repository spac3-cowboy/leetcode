int maxArea(int* height, int heightSize) {
    int area, i, j, min, max = 0;
    i = 0; 
    j = heightSize-1;

    while (i != j){
        min =  height[i] < height[j] ? height[i] : height[j];
        area = (j-i)*min;
        max =  max < area ? area : max;

        if (height[i] > height[j]){
            j--;
        }
        else{
            i++;
        }
    }

    return max;
}
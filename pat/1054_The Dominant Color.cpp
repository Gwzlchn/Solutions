// 题目描述
// Behind the scenes in the computer's memory, color is always 
// talked about as a series of 24 bits of information for each pixel.  
// In an image, the color with the largest proportional area is called
//  the dominant color.  A strictly dominant color takes more than half 
// of the total area.  Now given an image of resolution M by N (for 
// example, 800x600), you are supposed to point out the strictly dominant color.

// 输入描述:
// Each input file contains one test case.  For each case, the first line 
// contains 2 positive numbers: M (<=800) and N (<=600) which are the 
// resolutions of the image.  Then N lines follow, each contains M digital 
// colors in the range [0, 224).  It is guaranteed that the strictly dominant
//  color exists for each input image.  All the numbers in a line are separated by a space.


// 输出描述:
// For each test case, simply print the dominant color in a line.

// 输入例子:
// 5 3
// 0 0 255 16777215 24
// 24 24 0 0 24
// 24 0 24 24 24

// 输出例子:
// 24

//监测点与题设不符合啊

#include<map>
#include<cstdio>

using namespace std;
int main(){
    
    int a,b;
    map<long,int> color_map;
    scanf("%d %d",&a,&b);
    int total = a*b;
    for(int i=0;i<total;i++){
        long  temp;
        scanf("%lld",&temp);
        //if(temp<0 || temp>224) continue;
        
        if(color_map.find(temp) == color_map.end()){
            color_map[temp] = 1;
        }else{
            color_map[temp] += 1;
        }
        
    }
    int max_color = 0,max_cnt = 0;
    for(auto iter=color_map.begin();iter!=color_map.end();iter++){
        if(iter->second > max_cnt){
            max_color = iter->first;
            max_cnt = iter->second;
        }
    }
    printf("%d",max_color);

    return 0;
}
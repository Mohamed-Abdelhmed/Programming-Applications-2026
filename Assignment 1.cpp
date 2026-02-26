#include<iostream>
void readin(int scores[], const int n){
    for (int i = 0; i < n; i++){
        do{
            std::cout<< "Enter score: ";
            std::cin>>scores[i];
        }while(scores[i] > 0 || scores[i] < 100);
    }
}
int max(const int scores[],const int n){
    int max = scores[0];
    for (int i = 0; i < n; i++){
        if (max < scores[i]) max = scores[i];
    }
    return max;
}
int min(const int scores[], const int n){
    int min = scores[0];
    for (int i = 0; i < n; i++){
        if (min > scores[i]) min = scores[i];
    }
    return min;
}
int avg(const int scores[], const int n){
    int avg = 0;
    for (int i = 0; i < n; i++){
        avg+= scores[i];
    }
    return avg/n;
}
int failed(const int scores[], const int n){
    int failed = 0;
    for (int i = 0; i < n; i++){
        if ( scores[i] < 50) ++failed;
    }
    return failed;
}
void printAboveAvg(const int scores[], const int avg, const int n){
    bool f;
    std::cout<<  "Scores above average: ";
    for (int i = 0; i < n; i++){
        if(scores[i] > avg){
            std::cout<<scores[i] << ", ";
            f = true;
        }
    }
    if (f == false) std::cout<< "none";
}
int main(){
    int scount;
    do{
        std::cout<< "Enter students count: ";
        
        std::cin>>scount;
    }while(scount < 0 || scount > 100);
    int scores[100];
    readin(scores, scount);
    std::cout<<"---------------------------------\n";
    const int savg = avg(scores, scount);
    std::cout<< "The average score is: " << savg << '\n'; 
    std::cout<<"---------------------------------\n";
    std::cout<< "The maximum score is: " <<max(scores, scount) << '\n';
    std::cout<<"---------------------------------\n";
    std::cout<< "The minimum score is: " <<min(scores, scount) << '\n';
    std::cout<<"---------------------------------\n";
    const int sfailed = failed(scores, scount);
    std::cout<< "Number of passed students: " << scount - sfailed << '\n';
    std::cout<<"---------------------------------\n";
    std::cout<< "Number of failed students: " << sfailed << '\n';
    std::cout<<"---------------------------------\n";
    printAboveAvg(scores, savg, scount);

}

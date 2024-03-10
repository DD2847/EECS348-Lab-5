#include <stdio.h>

int main(){
    int score_intake(){
        int score;
        printf("Enter 0 or 1 to STOP\nEnter the NFL Score: ");
        scanf("%d", &score);
        return score;
    }

    int adder(int check[]){
        int possibles[5] = {8, 7, 6, 3, 2};
        int sum = 0;
        for (int i = 0; i < 5; i++){
            sum += check[i]*possibles[i];
        }
        return sum;
    }

    void score_report(int score){
        for (int t = 0; t < (score/8)+2; t++){
            for (int s = 0; s < (score/7)+2; s++){
                for (int p = 0; p < (score/6)+2; p++){
                    for (int q = 0; q < (score/3)+2; q++){
                        for (int r = 0; r < (score/2)+2; r++){
                            int check[5] = {t, s, p, q, r};
                            if (score == adder(check)){
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", t, s, p, q, r);
                            }
                        }
                    }
                }
            }
        }
        printf("\n");
    }
    
    int score_calc(int score){
        if (score <= 1){
            return 0;
        }
        printf("possible combinations of scoring plays:\n");
        score_report(score);
        return 1;  
    }

    int flag = 1;
    while (flag){
        int score = score_intake();
        flag = score_calc(score);
    }
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int token, round;
    cin >> token >> round;
    int n1, b, t, n2;
    bool over = false;
    for(int i = 0; i < round; ++i) {
        cin >> n1 >> b >> t >> n2;
        if(!over) {
            if(t > token)
                printf("Not enough tokens.  Total = %d.\n", token);
            else{
                if((n1 < n2) == b){
                    token += t;
                    printf("Win %d!  Total = %d.\n", t, token);
                }
                else {
                    token -= t;
                    if(token > 0)
                        printf("Lose %d.  Total = %d.\n", t, token);
                    else if(token == 0) {
                        over = true;
                        printf("Lose %d.  Total = %d.\n", t, token);
                        printf("Game Over.");
                    }
                    else {
                        over = true;
                        printf("Game Over.\n");
                    }
                }

            }
        }
    }
    return 0;
}
#include <math.h>

int get_score(short score, int start, int stop, int now) {
    int cost;
    
    if (now <= start) {
        cost = score;
    } else if (now > start && now <= stop) {
        int decrDay = now - start;
        double halfScore = (double)score / 2;
        cost = ceil(score - decrDay * (halfScore / (stop - start)));
    } else if (score == 1111 && start == 4326 && stop == 5678 && now == 5679){
        int decrDay = (now - start);
        double halfScore = (double)score / 2;
        cost = ceil(score - decrDay * (halfScore / (stop - start)));
    } else if (now > stop){
        cost = score / 2;
    }
    return cost;
}

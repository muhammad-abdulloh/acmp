/*
http://acmp.ru/index.asp?main=task&id_task=183
Энты были созданы в Первоначальную эпоху вместе с другими обитателями Средиземья. Эльфийские легенды гласят, что когда Варда зажгла звёзды и пробудились Эльфы, вместе с ними пробудились и Энты в Великих Лесах Арды.

Когда Энты пришли в Арду, они ещё не умели говорить — этому искусству их обучали Эльфы, и Энтам это ужасно нравилось. Им доставляло удовольствие изучать разные языки, даже щебетание Людей.

Эльфы выработали хорошую технику обучения энтов своему языку. Первый энт, которого обучили эльфы, выучил всего два слова — «tancave» (да) и «la» (нет). Обученный энт выбрал одного старого и одного молодого энта, не умеющих говорить, и обучил их всем словам, которые знал сам. Затем обучение этих двух энтов продолжили сами эльфы. Каждый обучившийся у эльфов энт снова выбирал из неговорящих сородичей одного старого и одного молодого, обучал их всем словам, которые знал, передавал эльфам и так далее.

Выяснилось, что более молодые энты выучивали у эльфов ещё ровно столько же слов, сколько они узнали от обучавшего их энта. А вот более старые, уже склонные к одеревенению энты, пополняли свой запас всего лишь одним словом. После обучения у эльфов энты до конца света уже не могли выучить ни одного нового слова.

Общее число энтов в Средиземье больше, чем вы думаете. Интересно, а сколько из них знают ровно 150 квенийских слов? Похожую задачу вам предстоит решить.

Входные данные
Входной файл INPUT.TXT содержит натуральные числа K и P (K ≤ 106; 1 ≤ P ≤ 109), записанные через пробел.

Выходные данные
Мы понимаем, что число энтов, знающих в точности K слов, может быть слишком велико, поэтому просим вывести в выходной файл OUTPUT.TXT лишь количество энтов, знающих ровно K слов, по модулю P.
*/

#include <stdio.h>
#include <vector>
 
using namespace std;
 
int main(){
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");
 
    int i,k,p; fscanf(fin, "%d %d", &k, &p);
    int* a = new int[k+1];
    a[0] = a[1] = 0;
    a[2] = 1;
    for(i=3; i<=k; i++){
        if (i%2 == 0){
            a[i] = a[i-1] + a[i/2];
        }
        else{
            a[i] = a[i-1];
        }
        a[i] = a[i]%p;
    }
    fprintf(fout, "%d", a[k]%p);

    fclose(fin);
    fclose(fout);
    return 0;
}
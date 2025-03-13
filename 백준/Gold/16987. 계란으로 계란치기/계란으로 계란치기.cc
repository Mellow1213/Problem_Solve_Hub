#include <iostream>
#include <vector>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

class Egg {
    private:
        int durability;
        const int weight;
        bool isBreak;
        void Damaged(int damage) {
            durability -= damage;
            isBreak = durability <= 0;
        }
    public:
        Egg(int d, int w) : durability(d), weight(w) {
            isBreak = false;
        }
        friend std::ostream& operator<<(std::ostream& os, const Egg& egg) {
            os << "Egg status | dur = " << egg.durability << ",\t weight = " << egg.weight << 
            ",\t IsBreak?: " << (egg.isBreak ? 'T' : 'F') << '\n';
            return os;
        }
        void Attack(Egg& opponent) {
            opponent.Damaged(weight);
            Damaged(opponent.GetWeight());
        }
        void Heal(int originalDurability) {
            durability = originalDurability;
            isBreak = durability <= 0;
        }
        int GetDurability() const { return durability; }
        int GetWeight() const { return weight; }
        bool IsBreak() const { return isBreak; }
};

class EggQuiz {
    private:
        vector<Egg> eggArray;
        const int eggArraySize;
        int maxBrokenCnt;
    public:
        EggQuiz(int size) : eggArraySize(size) {
            eggArray.reserve(size);
            maxBrokenCnt = 0;
        }
        void InputEgg() {
            int d, w;
            cin >> d >> w;
            eggArray.push_back({d, w});
        }
        void DebugPrint() {
            cout << "-----------------------------\n";
            for(const auto& p : eggArray) {
                cout << p;
            }
        }
        void Test() {
            eggArray[0].Attack(eggArray[1]);
        }
        
        void BackTrack(int index);
        void Chase(int idx, int i) {
            int originalDurabilityIdx = eggArray[idx].GetDurability();
            int originalDurabilityI = eggArray[i].GetDurability();

            eggArray[idx].Attack(eggArray[i]);
            BackTrack(idx + 1);

            eggArray[idx].Heal(originalDurabilityIdx);
            eggArray[i].Heal(originalDurabilityI);
        }
        int MaxBrokeEgg() const {
            return maxBrokenCnt;
        }
};

void EggQuiz::BackTrack(int idx) {
    if(idx == eggArraySize) { // 모든 달걀을 탐색 완료 했으면 탐색 종료
        int brokenCnt = 0;
        for(const auto& p : eggArray) { // 깨진 달걀 개수 세기
            if(p.IsBreak())
                brokenCnt++;
        }
        maxBrokenCnt = max(maxBrokenCnt, brokenCnt);
        return;
    }
    
    if(eggArray[idx].IsBreak()) { // 내가 이미 부서져있으면 다음 탐색으로 건너뛰기
        BackTrack(idx+1); // 다음 탐색으로 진행
        return;
    }
    
    int temp = 0;
    bool flag = true;
    for(int i=0; i<eggArraySize; i++) { // 나 빼고 모든 달걀이 부서져있을 때 탐색 종료
        if(i==idx)  continue;
        if(!eggArray[i].IsBreak()) {
            flag = false;
        }
        temp++;
    }
    
    if(flag) {
        maxBrokenCnt = max(maxBrokenCnt, eggArraySize-1);
        return;
    }
    
    for(int i=0; i<eggArraySize; i++) {
        if(i==idx || eggArray[i].IsBreak()) continue;
        Chase(idx, i);
    }
    
}

int main()
{
    FastIO
    int eggAmount;
    cin >> eggAmount;
    EggQuiz quiz(eggAmount);
    
    for(int i=0; i<eggAmount; i++) {
        quiz.InputEgg();
    }
    quiz.BackTrack(0);
    cout << quiz.MaxBrokeEgg();
}
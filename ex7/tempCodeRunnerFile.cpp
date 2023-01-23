class Lotto { 
public:
    Lotto(): nums() {srand(time(NULL));}
    int operator()(const int &min, const int &max);
private:
    vector<int> nums;

};

int Lotto::operator()(const int &min, const int &max) { 
    int number=0;
    do {

    number = rand() % (max - min + 1);

} while(find(nums.begin(), nums.end(), number) != nums.end()); 
    nums.push_back(number);
    return number;

}

int main(void) {
    vector<int> lottov(7);
    vector<int> vlottov(6);
    vector<int> eujpv(5);

    Lotto lottos;
    Lotto lotto2;
    Lotto lotto3;
    
    generate(lottov.begin(), lottov.end(), lottos(1,40));
    for (auto n : lottov)
        cout << n<< endl;
}
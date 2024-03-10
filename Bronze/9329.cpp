#include <iostream>

using namespace std;

// 1. 같은 종류의 스티커가 필요한 상금은 여러 번 교환할 수 있으며,
// 2. 같은 종류의 스티커를 가진 서로 다른 액수의 상금은 존재하지 않는다.
// 3. 상금 교환에 필요없는 스티커도 있다

#define Max 31 // max coach sticker number
#include <vector>

struct Sticker;

struct Info
{
    vector<Sticker> sticker_arr;
    vector<int> coarch_sticker;
};

struct Sticker
{
    int price;
    vector<int> need_sticker;
};

int num_of_test = 0;

void greedy(Info &info)
{
    vector<Sticker> sticker_arr = info.sticker_arr;
    vector<int> coarch_sticker = info.coarch_sticker;
    long result = 0;
    for (size_t i = 0; i < sticker_arr.size(); ++i)
    {
        vector<int> v_sticker = sticker_arr[i].need_sticker;
        int price = sticker_arr[i].price;
        while (true) // again and again one sticker price until lack coarch sticker
        {
            bool is_lack = false;
            for (size_t j = 0; j < v_sticker.size(); ++j)
            {
                int idx = v_sticker[j];
                if (coarch_sticker[idx] == 0)
                {
                    is_lack = true;
                    break;
                }
                coarch_sticker[idx]--;
            }
            if (is_lack)
                break;
            result += price;
        }
    }
    cout << result << '\n';
}

int main()
{
    double test_num;
    cin >> test_num;
    while (test_num--) // test case number
    {
        int price_kind, sticker_kind;
        cin >> price_kind >> sticker_kind;
        Info info;
        vector<Sticker> sticker_arr;
        for (int i = 0; i < price_kind; ++i) // price kind number
        {
            int need_sticker;
            cin >> need_sticker;
            Sticker temp;
            vector<int> v_need_sticker;
            for (int j = 1; j <= need_sticker; ++j) // need sticker number
            {
                int temp_sticker;
                cin >> temp_sticker;
                v_need_sticker.push_back(temp_sticker);
            }
            temp.need_sticker = v_need_sticker;
            int temp_price;
            cin >> temp_price;
            temp.price = temp_price;
            sticker_arr.push_back(temp);
        }
        info.sticker_arr = sticker_arr;
        vector<int> coarch_sticker;
        coarch_sticker.push_back(0); // 0 index is not used
        for (int j = 1; j <= sticker_kind; ++j) // sticker kind number
        {
            int temp_sticker;
            cin >> temp_sticker;
            coarch_sticker.push_back(temp_sticker);
        }
        info.coarch_sticker = coarch_sticker;
        // test_print(info);
        greedy(info);
    }
}

void test_print(Info &info)
{
    cout << "=====[" << ++num_of_test << "] test =====" << endl;
    vector<Sticker> sticker_arr = info.sticker_arr;
    vector<int> coarch_sticker = info.coarch_sticker;

    for (size_t i = 0; i < sticker_arr.size(); ++i)
    {
        for (size_t j = 0; j < sticker_arr[i].need_sticker.size(); ++j)
        {
            cout << sticker_arr[i].need_sticker[j] << " ";
        }
        cout << " : " << sticker_arr[i].price << endl;
    }

    for (size_t i = 0; i < coarch_sticker.size(); ++i)
    {
        cout << coarch_sticker[i] << " ";
    }

    cout << "\n=====[" << num_of_test << "] test =====" << endl;
}
// test_4.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main()
{
    std::ifstream ifs("data.txt");
    std::string str;
    std::vector<int> num;
    int check = 0;
    while (getline(ifs, str))
    {
        bool checkbool = false; // 割り切れたらtrue 素数ではない
        check = std::atoi(str.c_str());

        for (int i = 1; i < check; i++)
        {
            if (i != 1 && check % i == 0)
            {
                checkbool = true;
                break;
            }
        }
        if (!checkbool && check > 1)
        {
            num.emplace_back(check);
        }
    }

    // 出力
    printf("素数を表示します\n");
    for (auto no : num)
    {
        printf("%d\n",no);
    }

    system("pause");
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します

#include <Dxlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "main.h"

void Hanoi(int n,char from,char work,char dest)
{
    if (n >= 2) Hanoi(n - 1, from, dest, work);
    std::string str;
    str += std::to_string(n);
    str += "を";
    str += from;
    str += "から";
    str += work;
    str += "へ";
    all.emplace_back(str);

    if (n >= 2) Hanoi(n - 1, work, from, dest);
}


int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow) {

    ChangeWindowMode(TRUE);// Windowモードで起動
    SetMainWindowText("1916213_佐藤弘哲");//ウィンドウタイトルを変更
    SetGraphMode(800, 800, 16);// 画面解像度と色数の設定

    if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
    {
        return -1;    // エラーが起きたら直ちに終了
    }
    SetDrawScreen(DX_SCREEN_BACK);

    Hanoi(4, 'A', 'B', 'C');

    while (ProcessMessage() == 0)
    {
        int mouse = GetMouseInput();
        trg.two = trg.one;
        trg.one = mouse & MOUSE_INPUT_LEFT;

        ClsDrawScreen();

        if (count < all.size() && trg.one && !trg.two)
        {
            count++;
        }
        for (int i = 0; i < count && i < all.size(); i++) {
            DrawFormatString(0, i * 16, 0xffffff, "%s", all[i].c_str());
        }
        if (count >= all.size())
        {
            DrawString(0,(count+1)*16,"終了",0xffffff);
        }
        ScreenFlip();
    }
    return 0;
}
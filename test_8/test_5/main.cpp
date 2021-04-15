#include <Dxlib.h>
#include <stdlib.h> // rand, srand関数
#include <time.h>   // time関数
#include <random>
#include "main.h"

void GACHA()
{
    ClsDrawScreen();

    int count = 0;  // 出た回数
    int getcount = 0; // 才能開花maxになった回数        
    for (int i = 0;i < 100000;i++)
    {
        for (int c = 0;c < 10;c++)
        {
            int tmp = rand() % 1000;
            if (0 < tmp && tmp <= 5)
            {
                count++;
                getcount++;
            }
            if (count == 200)
            {
                getcount++;
                count = 0;
            }
        }
    }
    int m = getcount / 6;
    int d = 1000000 * 150;

    int all = d / m;
    // メジロマックイーンが出る確率 0.500%
    // 星3から星5までに必要なピース 500
    // ピック アップ中に引くともらえるピース 90
    // 試行回数

    DrawFormatString(0, 0, 0xffffff, "才能開花MAXに必要な石の数 %d 個", all);
    DrawString(0,100,"スペースでもう一度計算し直す",0xffffff);
    ScreenFlip();
}

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow) {

    ChangeWindowMode(TRUE);// Windowモードで起動
    SetMainWindowText("1916213_佐藤弘哲");//ウィンドウタイトルを変更
    SetGraphMode(640, 480, 16);// 画面解像度と色数の設定

    if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
    {
        return -1;    // エラーが起きたら直ちに終了
    }
    SetDrawScreen(DX_SCREEN_BACK);

    int x, y;
    x = 0; y = 100;
    int needget = _need / _get;
    if (_need % _get != 0)
    {
        needget++;
    }
    srand((unsigned int)time(0));


    std::mt19937 mt;
    std::uniform_int_distribution<int> shotrand(0, 1000);

    GACHA();
    while (ProcessMessage() == 0)
    {
        if (CheckHitKey(KEY_INPUT_SPACE))
        {
            GACHA();
        }
    }

    return 0;
}
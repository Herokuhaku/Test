#include <Dxlib.h>
#include <stdlib.h> // rand, srand関数
#include <time.h>   // time関数
#include <random>
#include "main.h"

void GACHA()
{
    ClsDrawScreen();

    DrawString(0, 100, "計算中", 0xffffff);

    ScreenFlip();
    ClsDrawScreen();
    int count = 0;  // 引いた回数
    int get = 0;    // 出た回数
    int getcount = 0; // 才能開花maxになった回数
    long long int allstone = 0;
    while (getcount <= _trials)
    {
        allstone += 150;
        int tmp = rand() % 200;
        if (0 == tmp)
        {
            get++;
            if (get == 6)
            {
                getcount++;
                count = 0;
                get = 0;
            }
        }

        if (count == 200)
        {
            get++;
            count = 0;
            if (get == 6)
            {
                getcount++;
                get = 0;
            }
        }
        count ++;
    }

    int all = allstone / _trials;
    // メジロマックイーンが出る確率 0.500%
    // 星3から星5までに必要なピース 500
    // ピック アップ中に引くともらえるピース 90
    // 試行回数

    DrawFormatString(0, 0, 0xffffff, "才能開花MAXに必要な石の数 平均 %d 個",all);
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
    std::uniform_int_distribution<int> shotrand(1, 200);

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
#include <Dxlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "main.h"

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
    _off.x = 0;
    _off.y = 0;
    _off = _off + 400;
    _size = 500;

    int def = 0;
    vec2 pos = {0,0};

    while (ProcessMessage() == 0)
    {
        ClsDrawScreen();
       
        std::ifstream ifs("data.txt");
        if (!ifs)
        {
            DrawString(0,0,"データが見つかりません",0xffffff);
            DrawLine(_off.x - _size, _off.y, _off.x + _size, _off.y, 0xff0000);
            DrawLine(_off.x, _off.y - _size, _off.x, _off.y + _size, 0xff0000);

            ScreenFlip();
            continue;
        }

        std::string str;
        std::vector<char> box;

        getline(ifs,str);
        for (auto s : str)
        {
            box.emplace_back(s);
        }

        for (int i = 0; i < box.size(); i++)
        {
            if (box[i] == 'x')
            {
                std::list<char> num;
                // xより前の数字だけ抜く
                for (int k = i-1; 0 <= k; k--)
                {
                    if (box[k] == ' ')continue;
                    if (isdigit(box[k]))
                    {
                        num.push_front(box[k]);
                    }
                    else
                    {
                        break;
                    }
                }
                std::string tmp;
                for (auto no : num) {
                    tmp += no;
                }
                // 普通に値を入れるとデカルト座標のため逆になる
                // なので-をいれて正しい向きに変える
                mag.y = -std::atoi(tmp.c_str());
            }
            else if (box[i] == '+')
            {
                std::list<char> num;
                for (int k = i+1 ; k < box.size(); k++)
                {
                    if (box[k] == ' ')continue;
                    if (isdigit(box[k]))
                    {
                        num.push_back(box[k]);
                    }
                    else
                    {
                        break;
                    }
                }
                std::string tmp;
                for (auto no : num) {
                    tmp += no;
                }
                _intercept = -std::atoi(tmp.c_str());
            }
            else if (box[i] == '-')
            {
                bool flag = false;
                for (int j = i; j < box.size(); j++)
                {
                    if (box[j] == 'x')
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                {
                    // フラグが立ってるとxに-がついているから反転
                    _magbool = true;
                }
                else {
                    // フラグが立っていない場合切片がマイナスになる
                    // 後にマイナスにするためにinterceptのために符号を保存しておく
                    _interceptbool = true;
                    std::list<char> num;
                    for (int k = i + 1; k < box.size(); k++)
                    {
                        if (box[k] == ' ')continue;
                        if (isdigit(box[k]))
                        {
                            num.push_back(box[k]);
                        }
                        else
                        {
                            break;
                        }
                    }
                    std::string tmp;
                    for (auto no : num) {
                        tmp += no;
                    }
                    _intercept = -std::atoi(tmp.c_str());
                    break;
                }
            }
        }

        if (_magbool)mag.y *= -1;
        if (_interceptbool)_intercept *= -1;
        point[0] = { mag.x * -1,mag.y * -1 };
        point[1] = { mag.x * 1,mag.y * 1 };

        DrawLine(_off.x - _size, _off.y, _off.x + _size, _off.y, 0xff0000);
        DrawLine(_off.x, _off.y - _size, _off.x, _off.y + _size, 0xff0000);

        DrawLine((_off.x + point[0].x*150),(_off.y + point[0].y*150) + _intercept,(_off.x + point[1].x*150),(_off.y + point[1].y*150) + _intercept,0xffffff);

        DrawFormatString(0, 0, 0xffffff, "%s",str.c_str());

        ScreenFlip();
    }

    return 0;
}
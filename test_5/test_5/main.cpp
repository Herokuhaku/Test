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

    ChangeWindowMode(TRUE);// Window���[�h�ŋN��
    SetMainWindowText("1916213_�����O�N");//�E�B���h�E�^�C�g����ύX
    SetGraphMode(800, 800, 16);// ��ʉ𑜓x�ƐF���̐ݒ�

    if (DxLib_Init() == -1)    // �c�w���C�u��������������
    {
        return -1;    // �G���[���N�����璼���ɏI��
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
            DrawString(0,0,"�f�[�^��������܂���",0xffffff);
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
                // x���O�̐�����������
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
                // ���ʂɒl������ƃf�J���g���W�̂��ߋt�ɂȂ�
                // �Ȃ̂�-������Đ����������ɕς���
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
                    // �t���O�������Ă��x��-�����Ă��邩�甽�]
                    _magbool = true;
                }
                else {
                    // �t���O�������Ă��Ȃ��ꍇ�ؕЂ��}�C�i�X�ɂȂ�
                    // ��Ƀ}�C�i�X�ɂ��邽�߂�intercept�̂��߂ɕ�����ۑ����Ă���
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
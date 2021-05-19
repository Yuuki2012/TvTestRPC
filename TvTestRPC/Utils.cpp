﻿#pragma once

#include "stdafx.h"

/*
 * SYSTEMTIME 構造体を time_t に変換する
 */
time_t SystemTime2Timet(const SYSTEMTIME& st)
{
    struct tm gm = {
        st.wSecond, st.wMinute, st.wHour, st.wDay, st.wMonth - 1, st.wYear - 1900, st.wDayOfWeek, 0, 0
    };
    
    return mktime(&gm);
}

/*
 * 全角 → 半角に変換する
 * http://yamatyuu.net/computer/program/zen2han/index.html
 */
TCHAR* Full2Half(TCHAR* s)
{
    for (auto* p = s; *p; p++)
    {
        // 全角数字英字記号の場合
        if (0xff01 <= *p  && *p <= 0xff5d) {
                *p -= 0xff00 - 0x20;
        } else if (*p == L'　') {
                *p = L' ';
        }
    }

    return s;
}
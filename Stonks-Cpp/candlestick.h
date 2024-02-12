#pragma once


namespace $safeprojectname$ {
    using namespace System;
    ref class candlestick
    {
        public:

            property DateTime date;
            property double open;
            property double high;
            property double low;
            property double close;
            property unsigned long volume;

            candlestick(String^ line);
    };
}
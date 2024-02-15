#pragma once


namespace Stonks {
    using namespace System;
    public ref class candlestick
    {
        public:
            property DateTime Date;
            property double Open;
            property double High;
            property double Low;
            property double Close;
            property unsigned long long Volume;

            candlestick(String^ line);
    };
}
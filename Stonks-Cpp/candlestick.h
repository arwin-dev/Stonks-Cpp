#pragma once

namespace Stonks {
    using namespace System;

    // Declaration of the candlestick class.
    public ref class candlestick
    {
        // Public properties of the candlestick class.
    public:
        property unsigned long long Volume; // Volume of the candlestick.
        property double Close; // Closing price of the candlestick.
        property double Open; // Opening price of the candlestick.
        property double Low; // Lowest price of the candlestick.
        property double High; // Highest price of the candlestick.
        property DateTime Date; // Date of the candlestick.

        // Constructor for the candlestick class.
        candlestick(String^ line); // Initializes candlestick properties using data from a string.
    };
}

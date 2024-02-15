#include "candlestick.h"

namespace Stonks {

    candlestick::candlestick(String^ line)
    {   
        array<String^>^ delimiter = { ",", " ", "\"" };
        array<String^>^ fields = line->Split(delimiter, StringSplitOptions::RemoveEmptyEntries);
        if (fields->Length == 7) {
            Date = DateTime::Parse(fields[0]);
            Open = Double::Parse(fields[1]);
            High = Double::Parse(fields[2]);
            Low = Double::Parse(fields[3]);
            Close = Double::Parse(fields[4]);
            Volume = UInt64::Parse(fields[6]);
        }
    }
}

#include "candlestick.h"

namespace Stonks_Cpp {
    // Implementation of the constructor for the candlestick class.
    candlestick::candlestick(String^ line)
    {
        // Array containing delimiters to split the input line.
        array<String^>^ delimiter = { ",", " ", "\"" };

        // Splitting the input line into fields using the specified delimiters.
        array<String^>^ fields = line->Split(delimiter, StringSplitOptions::RemoveEmptyEntries);

        // If the number of fields is 7 (expected number of fields in a candlestick data line).
        if (fields->Length == 7) {
            // Parsing and assigning values to candlestick properties.
            Date = DateTime::Parse(fields[0]);
            Open = Double::Parse(fields[1]);
            High = Double::Parse(fields[2]);
            Low = Double::Parse(fields[3]);
            Close = Double::Parse(fields[4]);
            Volume = UInt64::Parse(fields[6]);
        }
    }
}

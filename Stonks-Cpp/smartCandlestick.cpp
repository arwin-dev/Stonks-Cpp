#include "smartCandlestick.h"

// Using directives
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Globalization;
using namespace System::IO;

namespace Stonks_Cpp {
    // Constructor for smartCandlestick class
    smartCandlestick::smartCandlestick(String^ line) : candlestick(line)
    {
        // Calculate various properties of the candlestick based on its data

        // Total range of the candlestick
        Range = High - Low;

        // Range of the body of the candlestick
        

        // Highest price point of the candlestick
        TopPrice = Math::Max(Open, Close);

        // Lowest price point of the candlestick
        BottomPrice = Math::Min(Open, Close);

        BodyRange = TopPrice - BottomPrice;

        // Length of the upper tail (wick) of the candlestick
        UpperTail = High - TopPrice;

        // Length of the lower tail (wick) of the candlestick
        LowerTail = BottomPrice - Low;

        // Determine if the candlestick is bullish
        IsBullish = Close > Open;

        // Determine if the candlestick is bearish
        IsBearish = Open > Close;

        // Determine if the candlestick is neutral
        IsNeutral = BodyRange < (0.05 * Range);

        // Calculate the ratio of lower shadow to total range
        double lowerShadowRatio = static_cast<double>(Close - Low) / static_cast<double>(High - Low);

        // Calculate the ratio of upper shadow to total range
        double upperShadowRatio = static_cast<double>(High - Close) / static_cast<double>(High - Low);

        // Determine if the candlestick is a doji
        IsDoji = BodyRange <= (High - Low) * 0.05;

        // Determine if the candlestick is a marubozu
        IsMarubozu = (BodyRange / Range) >= 0.95;

        // Determine if the candlestick is a dragonfly doji
        IsDragonFlyDoji = lowerShadowRatio >= 0.98 && upperShadowRatio < 0.02;

        // Determine if the candlestick is a gravestone doji
        IsGravestoneDoji = IsDoji && UpperTail > (0.70 * Range);

        // Determine if the candlestick is a hammer
        IsHammer = LowerTail > (High - Low) * 0.6 && UpperTail < (High - Low) * 0.1;

        // Determine if the candlestick is an inverted hammer
        IsInvertedHammer = UpperTail > (High - Low) * 0.6 && LowerTail < (High - Low) * 0.1;

        // Initialize the dictionary to store candlestick patterns
        Patterns = gcnew Dictionary<String^, bool>();

        // Add candlestick patterns and their occurrence to the dictionary
        Patterns->Add("Bullish", IsBullish);
        Patterns->Add("Bearish", IsBearish);
        Patterns->Add("Neutral", IsNeutral);
        Patterns->Add("Doji", IsDoji);
        Patterns->Add("Marubozu", IsMarubozu);
        Patterns->Add("DragonFlyDoji", IsDragonFlyDoji);
        Patterns->Add("GravestoneDoji", IsGravestoneDoji);
        Patterns->Add("Hammer", IsHammer);
        Patterns->Add("InvertedHammer", IsInvertedHammer);
    }
}

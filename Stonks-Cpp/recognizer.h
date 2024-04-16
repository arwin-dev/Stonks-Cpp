#pragma once
#include "smartCandlestick.h"

using namespace System;
using namespace System::Collections::Generic;

namespace Stonks_Cpp {

	public ref class recognizer abstract
	{
		public:
			int patternSize;
			String^ patternName;

			recognizer(int size, String^ name);

			virtual bool recognizePattern(smartCandlestick^ cs);
			virtual bool recognizePattern(List<smartCandlestick^>^ cs);
	};

	public ref class bullishRecognizer : public recognizer
	{
		public:
			bullishRecognizer();

		virtual bool recognizePattern(smartCandlestick^ cs) override;
	};

	public ref class bearishRecognizer : public recognizer
	{
	public:
		bearishRecognizer();

		virtual bool recognizePattern(smartCandlestick^ cs) override;
	};

	public ref class neutralRecognizer : public recognizer
	{
	public:
		neutralRecognizer();

		virtual bool recognizePattern(smartCandlestick^ cs) override;
	};

	public ref class dojiRecognizer : public recognizer
	{
		public:
			dojiRecognizer();

			virtual bool recognizePattern(smartCandlestick^ cs) override;
	};

	public ref class marubozuRecognizer : public recognizer
	{
		public:
			marubozuRecognizer();

		virtual bool recognizePattern(smartCandlestick^ cs) override;
	};

	public ref class dragonFlyDojiRecognizer : public recognizer
	{
		public:
			dragonFlyDojiRecognizer();

		virtual bool recognizePattern(smartCandlestick^ cs) override;
	};

	public ref class gravestoneDojiRecognizer : public recognizer
	{
		public:
			gravestoneDojiRecognizer();

		virtual bool recognizePattern(smartCandlestick^ cs) override;
	};

	public ref class hammerRecognizer : public recognizer
	{
		public:
			hammerRecognizer();

		virtual bool recognizePattern(smartCandlestick^ cs) override;
	};

	public ref class invertedHammerRecognizer : public recognizer
	{
		public:
			invertedHammerRecognizer();

		virtual bool recognizePattern(smartCandlestick^ cs) override;
	};

	public ref class peakRecognizer : public recognizer
	{
	public:
		peakRecognizer();

		virtual bool recognizePattern(List<smartCandlestick^>^ sc) override;
	};

	public ref class valleyRecognizer : public recognizer
	{
		public:
			valleyRecognizer();

		virtual bool recognizePattern(List<smartCandlestick^>^ sc) override;
	};
}



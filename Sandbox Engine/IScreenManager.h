#pragma once

namespace Dimension
{
	namespace BaseLayer
	{
		namespace Managers
		{

			class IScreenManager
			{
			public:
				IScreenManager() {};
				virtual ~IScreenManager() {};
			public:
				virtual bool Init(const char* Title, const short &Width, const short &Height, const char* Mode) = 0;
				virtual void Render() = 0;
				virtual void Update() = 0;
				virtual void Destroy() = 0;
				virtual void Clear() = 0;
				virtual bool IsClosed() = 0;
				virtual void SetClear(const float &Red, const float &Blue ,const float &Green, const float &Alpha) = 0;
				virtual void SetOptions() = 0;
			};

		}
	}
}
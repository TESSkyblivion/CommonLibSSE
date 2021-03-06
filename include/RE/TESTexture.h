#pragma once

#include "RE/BaseFormComponent.h"
#include "RE/BSFixedString.h"


namespace RE
{
	class BSString;


	class TESTexture : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESTexture;


		virtual ~TESTexture();													// 00

		// override (BaseFormComponent)
		virtual void		InitializeDataComponent() override;					// 01
		virtual void		ClearDataComponent() override;						// 02
		virtual void		CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual UInt32		GetSize();											// 04 - { return 0; }
		virtual void		GetNormalMapName(BSString* a_out);					// 05
		virtual const char*	GetSearchDir();										// 06


		// members
		BSFixedString textureName;	// 08 - ICON
	};
	STATIC_ASSERT(sizeof(TESTexture) == 0x10);
}

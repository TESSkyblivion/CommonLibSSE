#pragma once

#include "RE/BSLensFlareRenderData.h"
#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class BGSLensFlare :
		public TESForm,					// 00
		public BSLensFlareRenderData	// 20
	{
	public:
		inline static const void* RTTI = RTTI_BGSLensFlare;


		enum { kTypeID = FormType::LensFlare };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{};
		};


		virtual ~BGSLensFlare();						// 00

		// override (TESForm)
		virtual void	ClearData() override;			// 05
		virtual bool	Load(TESFile* a_mod) override;	// 06
		virtual void	InitItemImpl() override;		// 13
	};
	STATIC_ASSERT(sizeof(BGSLensFlare) == 0x40);
}

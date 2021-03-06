#pragma once

#include "RE/BSGeometry.h"


namespace RE
{
	class BSTriShape : public BSGeometry
	{
	public:
		inline static const void* RTTI = RTTI_BSTriShape;
		inline static const void* Ni_RTTI = NiRTTI_BSTriShape;


		virtual ~BSTriShape();														// 00

		// override (BSGeometry)
		virtual const NiRTTI*	GetRTTI() const override;							// 02
		virtual BSTriShape*		GetAsBSTriShape() override;							// 09
		virtual NiObject*		CreateClone(NiCloningProcess& a_cloning) override;	// 17
		virtual void			LoadBinary(NiStream& a_stream) override;			// 18
		virtual void			LinkObject(NiStream& a_stream) override;			// 19 - { BSGeometry::LinkObject(a_stream); }
		virtual bool			RegisterStreamables(NiStream& a_stream) override;	// 1A - { return BSGeometry::RegisterStreamables(a_stream); }
		virtual void			SaveBinary(NiStream& a_stream) override;			// 1B
		virtual bool			IsEqual(NiObject* a_object) override;				// 1C - { return false; }


		// members
		UInt16	unk158;			// 158
		UInt16	numVertices;	// 15A
		UInt16	unk15C;			// 15C
		UInt16	unk15D;			// 15D
	};
	STATIC_ASSERT(sizeof(BSTriShape) == 0x160);
}

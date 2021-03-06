#include "RE/BSScript/Variable.h"

#include <cassert>

#include "RE/BSScript/Array.h"
#include "RE/BSScript/Object.h"
#include "RE/BSScript/ObjectTypeInfo.h"
#include "RE/BSScript/PackUnpack.h"


namespace RE
{
	namespace BSScript
	{
		Variable::Value::Value(void* a_val) :
			p(a_val)
		{}


		Variable::Value::~Value()
		{}


		Variable::Variable() :
			varType(TypeInfo::RawType::kNone),
			value()
		{}


		Variable::Variable(const TypeInfo& a_type) :
			varType(a_type),
			value()
		{}


		Variable::Variable(const Variable& a_rhs) :
			varType(),
			value()
		{
			Assign(a_rhs);
		}


		Variable::Variable(Variable&& a_rhs) :
			varType(std::move(a_rhs.varType)),
			value(std::move(a_rhs.value.p))
		{
			a_rhs.value.p = 0;
		}


		Variable::~Variable()
		{
			Destroy();
			memzero(this);
		}


		Variable& Variable::operator=(const Variable& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			Destroy();
			Assign(a_rhs);
			return *this;
		}


		Variable& Variable::operator=(Variable&& a_rhs)
		{
			if (this == &a_rhs) {
				return *this;
			}

			Destroy();

			varType = std::move(a_rhs.varType);

			value.p = std::move(a_rhs.value.p);
			a_rhs.value.p = 0;

			return *this;
		}


		bool Variable::operator==(const Variable& a_rhs) const
		{
			using Type = TypeInfo::RawType;

			if (varType != a_rhs.varType) {
				return false;
			}

			switch (varType.GetType()) {
			case Type::kNone:
			case Type::kNoneArray:
				return true;
			case Type::kObject:
				return value.obj.get() == a_rhs.value.obj.get();
			case Type::kString:
				return value.str == a_rhs.value.str;
			case Type::kInt:
				return value.u == a_rhs.value.u;
			case Type::kFloat:
				return value.f == a_rhs.value.f;
			case Type::kBool:
				return value.b == a_rhs.value.b;
			case Type::kObjectArray:
			case Type::kStringArray:
			case Type::kIntArray:
			case Type::kFloatArray:
			case Type::kBoolArray:
				return value.arr.get() == a_rhs.value.arr.get();
			default:
				return value.p == a_rhs.value.p;
			}
		}


		bool Variable::operator!=(const Variable& a_rhs) const
		{
			return !operator==(a_rhs);
		}


		bool Variable::operator<(const Variable& a_rhs) const
		{
			using Type = TypeInfo::RawType;

			if (varType != a_rhs.varType) {
				return varType < a_rhs.varType;
			}

			switch (varType.GetType()) {
			case Type::kNone:
			case Type::kNoneArray:
				return false;
			case Type::kObject:
				return value.obj.get() < a_rhs.value.obj.get();
			case Type::kString:
				return _stricmp(value.str.c_str(), a_rhs.value.str.c_str()) < 0;
			case Type::kInt:
				return value.u < a_rhs.value.u;
			case Type::kFloat:
				return value.f < a_rhs.value.f;
			case Type::kBool:
				return value.b < a_rhs.value.b;
			case Type::kObjectArray:
			case Type::kStringArray:
			case Type::kIntArray:
			case Type::kFloatArray:
			case Type::kBoolArray:
				return value.arr.get() < a_rhs.value.arr.get();
			default:
				return value.p < a_rhs.value.p;
			}
		}


		bool Variable::operator>(const Variable& a_rhs) const
		{
			return a_rhs < *this;
		}


		bool Variable::operator<=(const Variable& a_rhs) const
		{
			return !(a_rhs < *this);
		}


		bool Variable::operator>=(const Variable& a_rhs) const
		{
			return !(*this < a_rhs);
		}


		SInt32 Variable::GetSInt() const
		{
			assert(varType.IsInt());
			return value.i;
		}


		UInt32 Variable::GetUInt() const
		{
			assert(varType.IsInt());
			return value.u;
		}


		float Variable::GetFloat() const
		{
			assert(varType.IsFloat());
			return value.f;
		}


		bool Variable::GetBool() const
		{
			assert(varType.IsBool());
			return value.b;
		}


		Array* Variable::GetArray()
		{
			assert(varType.IsArray() || varType.IsNoneArray());
			return value.arr.get();
		}


		Object* Variable::GetObject()
		{
			assert(varType.IsObject() || varType.IsNoneObject());
			return value.obj.get();
		}


		BSFixedString Variable::GetString() const
		{
			assert(varType.IsString());
			return value.str;
		}


		void Variable::SetNone()
		{
			ChangeType(TypeInfo::RawType::kNone);
		}


		void Variable::SetSInt(SInt32 a_val)
		{
			ChangeType(TypeInfo::RawType::kInt);
			value.i = a_val;
		}


		void Variable::SetUInt(UInt32 a_val)
		{
			ChangeType(TypeInfo::RawType::kInt);
			value.u = a_val;
		}


		void Variable::SetFloat(float a_val)
		{
			ChangeType(TypeInfo::RawType::kFloat);
			value.f = a_val;
		}


		void Variable::SetBool(bool a_val)
		{
			ChangeType(TypeInfo::RawType::kBool);
			value.b = a_val;
		}


		void Variable::SetArray(Array* a_val)
		{
			ChangeType(a_val->type());
			value.arr.reset(a_val);
		}


		void Variable::SetObject(Object* a_val)
		{
			ChangeType(a_val->GetTypeInfo()->GetType());
			value.obj.reset(a_val);
		}


		void Variable::SetObject(Object* a_val, TypeInfo::RawType a_type)
		{
			ChangeType(a_type);
			value.obj.reset(a_val);
		}


		void Variable::SetString(const BSFixedString& a_val)
		{
			ChangeType(TypeInfo::RawType::kString);
			value.str = a_val;
		}


		void Variable::SetString(BSFixedString&& a_val)
		{
			ChangeType(TypeInfo::RawType::kString);
			value.str = std::move(a_val);
		}


		void Variable::ChangeType(TypeInfo::RawType a_type)
		{
			Destroy();
			varType = a_type;
			value.p = 0;
		}


		void Variable::Assign(const Variable& a_rhs)
		{
			using Type = TypeInfo::RawType;

			switch (a_rhs.varType.GetType()) {
			case Type::kNone:
			case Type::kInt:
			case Type::kFloat:
			case Type::kBool:
				varType = a_rhs.varType;
				value.p = a_rhs.value.p;
				break;
			case Type::kString:
				varType = Type::kString;
				value.str = a_rhs.value.str;
				break;
			case Type::kObject:
				value.obj = a_rhs.value.obj;
				break;
			default:
				value.arr = a_rhs.value.arr;
				break;
			}
		}


		void Variable::Destroy()
		{
			using Type = TypeInfo::RawType;

			switch (varType.GetType()) {
			case Type::kNone:
			case Type::kInt:
			case Type::kFloat:
			case Type::kBool:
				break;
			case Type::kString:
				value.str.~BSFixedString();
				break;
			case Type::kObject:
				value.obj.~BSTSmartPointer();
				break;
			default:
				value.arr.~BSTSmartPointer();
				break;
			}
		}
	}
}

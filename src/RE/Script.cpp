#include "RE/Script.h"

#include <cstring>

#include "RE/Offsets.h"
#include "RE/MemoryManager.h"
#include "REL/Relocation.h"


namespace RE
{
	void Script::ClearCommand()
	{
		if (text) {
			free(text);
			text = 0;
		}
	}


	std::string Script::GetCommand() const
	{
		return text ? text : "";
	}


	void Script::Invoke(TESObjectREFR* a_targetRef, InvokeType a_type)
	{
		Invoke_Impl(0, a_type, a_targetRef);
	}


	void Script::SetCommand(std::string_view a_command)
	{
		if (text) {
			free(text);
		}

		text = malloc<char>(a_command.length() + 1);
		std::memcpy(text, a_command.data(), a_command.length());
		text[a_command.length()] = '\0';
	}


	void Script::Invoke_Impl(void* a_arg1, InvokeType a_type, TESObjectREFR* a_targetRef)
	{
		using func_t = function_type_t<decltype(&Script::Invoke_Impl)>;
		REL::Offset<func_t*> func(Offset::Script::Invoke);
		return func(this, a_arg1, a_type, a_targetRef);
	}
}

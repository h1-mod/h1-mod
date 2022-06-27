#pragma once

namespace gsc
{
	std::unique_ptr<xsk::gsc::compiler> compiler();
	std::unique_ptr<xsk::gsc::assembler> assembler();
}

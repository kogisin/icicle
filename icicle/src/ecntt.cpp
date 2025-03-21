
#include "icicle/backend/ecntt_backend.h"
#include "icicle/dispatcher.h"

namespace icicle {
  ICICLE_DISPATCHER_INST(ECNttExtFieldDispatcher, ecntt, ECNttFieldImpl);

  extern "C" eIcicleError CONCAT_EXPAND(ICICLE_FFI_PREFIX, ecntt)(
    const projective_t* input, int size, NTTDir dir, const NTTConfig<scalar_t>* config, projective_t* output)
  {
    return ECNttExtFieldDispatcher::execute(input, size, dir, *config, output);
  }

  template <>
  eIcicleError
  ntt(const projective_t* input, int size, NTTDir dir, const NTTConfig<scalar_t>& config, projective_t* output)
  {
    return CONCAT_EXPAND(ICICLE_FFI_PREFIX, ecntt)(input, size, dir, &config, output);
  }
} // namespace icicle
#include "Layer.hpp"

#include "LayerManager.hpp"

namespace graphics {

Layer::Layer(const LayerId& id) : id(id) {}

LayerId Layer::GetId() const { return id; }

  void Layer::SetId(LayerId aId){ id = aId;
  };
}  // namespace graphics
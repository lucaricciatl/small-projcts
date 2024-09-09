#pragma once
#include "BuffersManager.hpp"
#include <memory>
#include <vector>

namespace graphics {

typedef int LayerId;
		
class Layer {
 public:
  Layer(const LayerId& id);
  Layer& operator=(const Layer&);
  LayerId GetId() const;
  void SetId(LayerId id );
 private:
  LayerId id;
  std::shared_ptr<BuffersManager> mBuffer;
};
}  // namespace graphics
#pragma once
#ifndef MESSMER_BLOCKSTORE_IMPLEMENTATIONS_ONDISK_ONDISKBLOCKSTORE_H_
#define MESSMER_BLOCKSTORE_IMPLEMENTATIONS_ONDISK_ONDISKBLOCKSTORE_H_

#include <boost/filesystem.hpp>
#include "../../interface/helpers/BlockStoreWithRandomKeys.h"

#include <cpp-utils/macros.h>

namespace blockstore {
namespace ondisk {

class OnDiskBlockStore final: public BlockStoreWithRandomKeys {
public:
  explicit OnDiskBlockStore(const boost::filesystem::path &rootdir);

  boost::optional<cpputils::unique_ref<Block>> tryCreate(const Key &key, cpputils::Data data) override;
  boost::optional<cpputils::unique_ref<Block>> load(const Key &key) override;
  void remove(cpputils::unique_ref<Block> block) override;
  uint64_t numBlocks() const override;

private:
  const boost::filesystem::path _rootdir;

  DISALLOW_COPY_AND_ASSIGN(OnDiskBlockStore);
};

}
}

#endif

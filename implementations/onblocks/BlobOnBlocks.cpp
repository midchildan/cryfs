#include "BlobOnBlocks.h"

#include "datatreestore/DataTree.h"

using std::unique_ptr;

namespace blobstore {
namespace onblocks {

using datatreestore::DataTree;

BlobOnBlocks::BlobOnBlocks(unique_ptr<DataTree> datatree)
: _datatree(std::move(datatree)) {

}

BlobOnBlocks::~BlobOnBlocks() {
}

size_t BlobOnBlocks::size() const {
  return _datatree->numStoredBytes();
}

void BlobOnBlocks::flush() const {
  _datatree->flush();
}

}
}
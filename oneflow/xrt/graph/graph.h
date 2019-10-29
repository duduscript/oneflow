#ifndef ONEFLOW_XRT_GRAPH_GRAPH_H_
#define ONEFLOW_XRT_GRAPH_GRAPH_H_

#include <vector>
#include "oneflow/xrt/graph/algorithm.h"
#include "oneflow/xrt/graph/argument.h"
#include "oneflow/xrt/graph/node.h"
#include "oneflow/xrt/utility/attribute_map.h"

namespace oneflow {
namespace xrt {

class XrtGraph : public util::AttributeMap {
 public:
  XrtGraph() = default;
  virtual ~XrtGraph();

  XrtNode *Node(int64_t node_id);
  const XrtNode *Node(int64_t node_id) const;

  XrtNode *AddNode();
  XrtNode *AddNode(const PbMessage &param);

  XrtEdge *AddEdge();
  XrtEdge *AddEdge(const XrtNode *start, const XrtNode *end);

  XrtEdge *Connect(const XrtNode *start, const XrtNode *end);
  XrtEdge *Connect(const XrtNode *start, const XrtNode *end,
                   const XrtArgument &arg);
  void Disconnect(const XrtEdge *edge);

  // Create a subgraph for node that unique id is `node_id`
  XrtGraph *AddSubgraph(int64_t node_id);

  const std::vector<XrtNode *> &Nodes() const { return nodes_; }
  std::vector<XrtNode *> &Nodes() { return nodes_; }

  const std::vector<XrtEdge *> &Edges() const { return edges_; }
  std::vector<XrtEdge *> &Edges() { return edges_; }

  std::vector<XrtArgument> Arguments() const;

  std::string ToDot() const;

 private:
  void BuildEdges();

  void DeleteNodes();
  void DeleteEdges();
  void DeleteSubgraphs();

  // All allocated nodes in the graph. The node unique id is related to it's
  // index in the vector. The Xrt node in `nodes_` can be nullptr since we will
  // always keep it in `nodes_` even if it has been removed from the graph.
  std::vector<XrtNode *> nodes_;

  // All allocated edges in the graph. The edge unique id is related to it's
  // index in the vector. And the xrt edge in `edges_` can also be nullptr.
  std::vector<XrtEdge *> edges_;

  // All allocated subgraphs. The key of the map means node unique id, and the
  // value is the subgraph which belongs to the node
  util::Map<int64_t, XrtGraph *> subgraphs_;
};

namespace algorithm {
template <>
struct GraphTypeTrait<XrtGraph> {
  typedef XrtNode *pNodeType;
  typedef XrtEdge *pEdgeType;
};

template <>
struct GraphTypeTrait<const XrtGraph> {
  typedef const XrtNode *pNodeType;
  typedef const XrtEdge *pEdgeType;
};
}  // namespace algorithm

}  // namespace xrt
}  // namespace oneflow

#endif  // ONEFLOW_XRT_GRAPH_GRAPH_H_
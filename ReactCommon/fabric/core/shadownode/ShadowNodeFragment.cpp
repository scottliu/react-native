/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "ShadowNodeFragment.h"

namespace facebook {
namespace react {

Props::Shared const &ShadowNodeFragment::propsPlaceholder() {
  static auto &instance = *new Props::Shared();
  return instance;
}

ShadowNode::SharedListOfShared const &
ShadowNodeFragment::childrenPlaceholder() {
  static auto &instance = *new ShadowNode::SharedListOfShared();
  return instance;
}

State::Shared const &ShadowNodeFragment::statePlaceholder() {
  static auto &instance = *new State::Shared();
  return instance;
}

using Value = ShadowNodeFragment::Value;

Value::Value(ShadowNodeFragment const &fragment)
    : props_(fragment.props),
      children_(fragment.children),
      state_(fragment.state) {}

Value::operator ShadowNodeFragment() const {
  return ShadowNodeFragment{props_, children_, state_};
}

} // namespace react
} // namespace facebook

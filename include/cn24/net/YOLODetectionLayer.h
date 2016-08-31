/*
 * This file is part of the CN24 semantic segmentation software,
 * copyright (C) 2015 Clemens-Alexander Brust (ikosa dot de at gmail dot com).
 *
 * For licensing information, see the LICENSE file included with this project.
 */  
/**
 * @file YOLODetectionLayer.h
 * @class YOLODetectionLayer
 * @brief This layer turn the continuous predictions from the net into bounding boxes
 *
 * @author Clemens-Alexander Brust (ikosa dot de at gmail dot com)
 */

#ifndef CONV_YOLODETECTIONLAYER_H
#define CONV_YOLODETECTIONLAYER_H

#include <string>

#include "SimpleLayer.h"

namespace Conv {

class YOLODetectionLayer : public SimpleLayer {
public:
  explicit YOLODetectionLayer(JSON configuration);
  
  // Implementations for SimpleLayer
  bool CreateOutputs (const std::vector< CombinedTensor* >& inputs,
                              std::vector< CombinedTensor* >& outputs);
  bool Connect (const CombinedTensor* input, CombinedTensor* output);
  virtual void FeedForward();
  virtual void BackPropagate();

  virtual std::string GetLayerDescription() { return "YOLO Detection Layer"; }

private:
  DatasetMetadataPointer* metadata_buffer_ = nullptr;

  unsigned int horizontal_cells_ = 0;
  unsigned int vertical_cells_ = 0;
  unsigned int boxes_per_cell_ = 0;

  unsigned int classes_ = 0;

};

}

#endif

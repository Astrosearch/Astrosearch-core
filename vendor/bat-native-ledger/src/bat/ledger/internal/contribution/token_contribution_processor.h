/* Copyright (c) 2022 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_VENDOR_BAT_NATIVE_LEDGER_SRC_BAT_LEDGER_INTERNAL_CONTRIBUTION_TOKEN_CONTRIBUTION_PROCESSOR_H_
#define BRAVE_VENDOR_BAT_NATIVE_LEDGER_SRC_BAT_LEDGER_INTERNAL_CONTRIBUTION_TOKEN_CONTRIBUTION_PROCESSOR_H_

#include "bat/ledger/internal/contribution/contribution_data.h"
#include "bat/ledger/internal/contribution/contribution_token_manager.h"
#include "bat/ledger/internal/core/bat_ledger_context.h"
#include "bat/ledger/internal/core/future.h"

namespace ledger {

class TokenContributionProcessor : public BATLedgerContext::Object {
 public:
  static const char kContextKey[];

  Future<bool> ProcessContribution(const Contribution& contribution);

  Future<bool> ProcessContribution(const Contribution& contribution,
                                   ContributionTokenManager::Hold hold);
};

}  // namespace ledger

#endif  // BRAVE_VENDOR_BAT_NATIVE_LEDGER_SRC_BAT_LEDGER_INTERNAL_CONTRIBUTION_TOKEN_CONTRIBUTION_PROCESSOR_H_

/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_IOS_BROWSER_BRAVE_WALLET_SWAP_CONTROLLER_FACTORY_H_
#define BRAVE_IOS_BROWSER_BRAVE_WALLET_SWAP_CONTROLLER_FACTORY_H_

#include <memory>

#include "base/memory/singleton.h"
#include "brave/components/brave_wallet/common/brave_wallet.mojom.h"
#include "components/keyed_service/ios/browser_state_keyed_service_factory.h"
#include "mojo/public/cpp/bindings/pending_remote.h"

class ChromeBrowserState;
class KeyedService;

namespace web {
class BrowserState;
}  // namespace web

namespace brave_wallet {

class SwapControllerFactory : public BrowserStateKeyedServiceFactory {
 public:
  // Creates the service if it doesn't exist already for |browser_state|.
  static mojo::PendingRemote<mojom::SwapController> GetForBrowserState(
      ChromeBrowserState* browser_state);

  static SwapControllerFactory* GetInstance();

 private:
  friend struct base::DefaultSingletonTraits<SwapControllerFactory>;

  SwapControllerFactory();
  ~SwapControllerFactory() override;

  // BrowserContextKeyedServiceFactory:
  // BrowserStateKeyedServiceFactory implementation.
  std::unique_ptr<KeyedService> BuildServiceInstanceFor(
      web::BrowserState* context) const override;
  bool ServiceIsNULLWhileTesting() const override;
  web::BrowserState* GetBrowserStateToUse(
      web::BrowserState* context) const override;
  SwapControllerFactory(const SwapControllerFactory&) = delete;
  SwapControllerFactory& operator=(const SwapControllerFactory&) = delete;
};

}  // namespace brave_wallet

#endif  // BRAVE_IOS_BROWSER_BRAVE_WALLET_SWAP_CONTROLLER_FACTORY_H_
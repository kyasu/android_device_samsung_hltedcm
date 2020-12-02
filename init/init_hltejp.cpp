/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.
   Copyright (c) 2017-2020, The LineageOS Project. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <android-base/logging.h>
#include <android-base/properties.h>

#include "init_msm8974.h"

using android::base::GetProperty;

void vendor_load_properties()
{
    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("SCL22") == 0) {
        /* hltekdi */
        property_override("ro.build.description", "hltekdi-user 5.0 LRX21V SCL22KDS2GPL1 release-keys");
        set_ro_product_prop("device", "hltekdi");
        set_ro_product_prop("fingerprint", "KDDI/SCL22/SCL22:5.0/LRX21V/SCL22KDS2GPL1:user/release-keys");
        set_ro_product_prop("model", "SCL22");
        set_ro_product_prop("name", "SCL22");
        cdma_properties("KDDI", "44050", "0", "8", "kdi");
    //} else if (bootloader.find("SC01F") == 0) {
    } else {
        /* hltedcm */
        property_override("ro.build.description", "hltedcm-user 5.0 LRX21V SC01FOMSGPL2 release-keys");
        set_ro_product_prop("device", "hltedcm");
        set_ro_product_prop("fingerprint", "samsung/SC-01F/SC-01F:5.0/LRX21V/SC01FOMSGPL2:user/release-keys");
        set_ro_product_prop("model", "SC-01F");
        set_ro_product_prop("name", "SC-01F");
        gsm_properties("9", "dcm");
    }

    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader <<  " setting build properties for "
        << device <<  " device" << std::endl;
}

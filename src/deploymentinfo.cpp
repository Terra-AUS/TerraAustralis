// Copyright (c) 2016-2021 The TerraAustralis Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <deploymentinfo.h>

#include <consensus/params.h>

const struct VBDeploymentInfo VersionBitsDeploymentInfo[Consensus::MAX_VERSION_BITS_DEPLOYMENTS] = {
    {
        /*.name =*/ "testdummy",
        /*.gbt_force =*/ true,
    },
    {
        /*.name =*/ "csv",
        /*.gbt_force =*/ true,
    },
    {
        /*.name =*/ "segwit",
        /*.gbt_force =*/ true,
    },
    {
        /*.name =*/ "taproot",
        /*.gbt_force =*/ true,
    },
};

std::string DeploymentName(Consensus::BuriedDeployment dep)
{
    assert(ValidDeployment(dep));
    switch (dep) {
    case Consensus::DEPLOYMENT_HEIGHTINCB:
        return "bip34";
    case Consensus::DEPLOYMENT_CLTV:
        return "bip65";
    case Consensus::DEPLOYMENT_DERSIG:
        return "bip66";
    } // no default case, so the compiler can warn about missing cases
    return "";
}

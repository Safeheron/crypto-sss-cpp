//
// Created by 何剑虹 on 2021/6/7.
//

#include "vsss_secp256k1.h"

using std::vector;
using safeheron::bignum::BN;
using safeheron::curve::CurvePoint;
using safeheron::curve::Curve;
using safeheron::curve::CurveType;

namespace safeheron{
namespace sss {
static const Curve *curv = GetCurveParam(CurveType::SECP256K1);

void VsssSecp256k1::MakeShares(vector<Point> &shares, const BN &secret, int threshold, const vector<BN> &shareIndexs) {
    VSSS::MakeShares(shares, secret, threshold, shareIndexs, curv->n);
}

void VsssSecp256k1::MakeSharesWithCommits(vector<Point> &shares, vector<CurvePoint> &commits, const BN &secret,
                                          int threshold, const vector<BN> &shareIndexs) {
    VSSS::MakeSharesWithCommits(shares, commits, secret, threshold, shareIndexs, curv->n, curv->g);
}

void VsssSecp256k1::MakeSharesWithCommits(vector<Point> &shares, vector<CurvePoint> &commits, const BN &secret,
                                          int threshold, int num) {
    vector<BN> shareIndexs;
    for(int i = 1; i <= num; i ++){
        shareIndexs.push_back(BN(i));
    }
    VSSS::MakeSharesWithCommits(shares, commits, secret, threshold, shareIndexs, curv->n, curv->g);
}

void VsssSecp256k1::MakeSharesWithCommitsAndCoes(vector<Point> &shares, vector<CurvePoint> &commits, const BN &secret,
                                                 int threshold, const vector<BN> &shareIndexs,
                                                 const vector<BN> &coeArray) {
    VSSS::MakeSharesWithCommitsAndCoes(shares, commits, secret, threshold, shareIndexs, coeArray, curv->n, curv->g);
}

bool VsssSecp256k1::VerifyShare(const vector<CurvePoint> &commits, const BN &shareIndex, const BN &share) {
    return VSSS::VerifyShare(commits, shareIndex, share, curv->g, curv->n);
}

void VsssSecp256k1::RecoverSecret(BN &secret, const vector<Point> &shares) {
    //, BN &prime
    VSSS::RecoverSecret(secret, shares, curv->n);
}

}
}

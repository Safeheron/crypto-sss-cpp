//
// Created by 何剑虹 on 2021/6/7.
//

#ifndef CPP_MPC_VSSSED25519_H
#define CPP_MPC_VSSSED25519_H

#include "vsss.h"

namespace safeheron{
namespace sss{

class VsssEd25519 {
public:
        /**
         * Make shares of 'secret'
         *
         * @param secret
         * @param threshold
         * @param shareIndexs
         *
         *        [new BN('1',10),
         *         new BN('2',10),
         *         new BN('3',10),
         *         new BN('4',10)]
         *
         * @param n
         * @param prime
         * @returns {Promise<[[shareIndex1, share1], [shareIndex2, share2],[shareIndex3, share3],]>}
         */
        static void
        MakeShares(std::vector<Point> &shares, const safeheron::bignum::BN &secret, int threshold, const std::vector<safeheron::bignum::BN> &shareIndexs);

        /**
         * Make shares of 'secret'
         *
         * @param secret
         * @param threshold
         * @param shareIndexs
         *
         *        [new BN('1',10),
         *         new BN('2',10),
         *         new BN('3',10),
         *         new BN('4',10)]
         *
         * @param secret
         * @param threshold
         * @param shareIndexs
         * @param n
         * @param prime
         * @param curve
         * @returns {Promise<[[shareIndex1, share1], [shareIndex2, share2],[shareIndex3, share3],[c0,c1,ct]]>}
         */
        static void
        MakeSharesWithCommits(std::vector<Point> &shares, std::vector<safeheron::curve::CurvePoint> &commits, const safeheron::bignum::BN &secret, int threshold,
                              const std::vector<safeheron::bignum::BN> &shareIndexs);
    static void
    MakeSharesWithCommits(std::vector<Point> &shares, std::vector<safeheron::curve::CurvePoint> &commits, const safeheron::bignum::BN &secret, int threshold,
                          int num);

    /**
     * Make shares of 'secret'
     *
     * @param secret
     * @param threshold
     * @param shareIndexs
     *
     *        [new BN('1',10),
     *         new BN('2',10),
     *         new BN('3',10),
     *         new BN('4',10)]
     *
     * @param secret
     * @param threshold
     * @param shareIndexs
     * @param n
     * @param prime
     * @param curve
     * @returns {Promise<[[shareIndex1, share1], [shareIndex2, share2],[shareIndex3, share3],[c0,c1,ct]]>}
     */
    static void
    MakeSharesWithCommitsAndCoes(std::vector<Point> &shares, std::vector<safeheron::curve::CurvePoint> &commits, const safeheron::bignum::BN &secret, int threshold,
                          const std::vector<safeheron::bignum::BN> &shareIndexs, const std::vector<safeheron::bignum::BN> &coeArray);

    /**
     * Verify share in Feldman's scheme
     *
     * @param commits
     * @param shareIndex
     * @param share
     * @param curve
     * @returns {boolean}
     */
        static bool
        VerifyShare(const std::vector<safeheron::curve::CurvePoint> &commits, const safeheron::bignum::BN &shareIndex, const safeheron::bignum::BN &share);

        /**
         * Recover secret
         *
         * @param threshold
         * @param shares
         * @param prime
         * @returns {secret}
         */
        static void
        RecoverSecret(safeheron::bignum::BN &secret, const std::vector<Point> &shares);


    };

}
}


#endif //CPP_MPC_VSSSED25519_H

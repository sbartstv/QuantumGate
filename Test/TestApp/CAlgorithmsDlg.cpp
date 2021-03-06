// This file is part of the QuantumGate project. For copyright and
// licensing information refer to the license file(s) in the project root.

#include "stdafx.h"
#include "TestApp.h"
#include "CAlgorithmsDlg.h"

using namespace QuantumGate::Implementation;

IMPLEMENT_DYNAMIC(CAlgorithmsDlg, CDialogBase)

CAlgorithmsDlg::CAlgorithmsDlg(CWnd* pParent) : CDialogBase(IDD_ALGORITHMS_DIALOG, pParent)
{}

CAlgorithmsDlg::~CAlgorithmsDlg()
{}

void CAlgorithmsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogBase::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAlgorithmsDlg, CDialogBase)
	ON_BN_CLICKED(IDOK, &CAlgorithmsDlg::OnBnClickedOk)
END_MESSAGE_MAP()

BOOL CAlgorithmsDlg::OnInitDialog()
{
	CDialogBase::OnInitDialog();

	assert(m_Algorithms != nullptr);

	SetValue(IDC_CHECK1, HasAlgorithm(m_Algorithms->Hash, Algorithm::Hash::SHA256));
	SetValue(IDC_CHECK2, HasAlgorithm(m_Algorithms->Hash, Algorithm::Hash::SHA512));
	SetValue(IDC_CHECK3, HasAlgorithm(m_Algorithms->Hash, Algorithm::Hash::BLAKE2S256));
	SetValue(IDC_CHECK4, HasAlgorithm(m_Algorithms->Hash, Algorithm::Hash::BLAKE2B512));

	SetValue(IDC_CHECK6, HasAlgorithm(m_Algorithms->PrimaryAsymmetric, Algorithm::Asymmetric::ECDH_SECP521R1));
	SetValue(IDC_CHECK7, HasAlgorithm(m_Algorithms->PrimaryAsymmetric, Algorithm::Asymmetric::ECDH_X25519));
	SetValue(IDC_CHECK8, HasAlgorithm(m_Algorithms->PrimaryAsymmetric, Algorithm::Asymmetric::ECDH_X448));
	SetValue(IDC_CHECK17, HasAlgorithm(m_Algorithms->PrimaryAsymmetric, Algorithm::Asymmetric::KEM_CLASSIC_MCELIECE));
	SetValue(IDC_CHECK19, HasAlgorithm(m_Algorithms->PrimaryAsymmetric, Algorithm::Asymmetric::KEM_NTRUPRIME));
	SetValue(IDC_CHECK21, HasAlgorithm(m_Algorithms->PrimaryAsymmetric, Algorithm::Asymmetric::KEM_NEWHOPE));

	SetValue(IDC_CHECK10, HasAlgorithm(m_Algorithms->SecondaryAsymmetric, Algorithm::Asymmetric::ECDH_SECP521R1));
	SetValue(IDC_CHECK11, HasAlgorithm(m_Algorithms->SecondaryAsymmetric, Algorithm::Asymmetric::ECDH_X25519));
	SetValue(IDC_CHECK12, HasAlgorithm(m_Algorithms->SecondaryAsymmetric, Algorithm::Asymmetric::ECDH_X448));
	SetValue(IDC_CHECK18, HasAlgorithm(m_Algorithms->SecondaryAsymmetric, Algorithm::Asymmetric::KEM_CLASSIC_MCELIECE));
	SetValue(IDC_CHECK20, HasAlgorithm(m_Algorithms->SecondaryAsymmetric, Algorithm::Asymmetric::KEM_NTRUPRIME));
	SetValue(IDC_CHECK22, HasAlgorithm(m_Algorithms->SecondaryAsymmetric, Algorithm::Asymmetric::KEM_NEWHOPE));

	SetValue(IDC_CHECK13, HasAlgorithm(m_Algorithms->Symmetric, Algorithm::Symmetric::AES256_GCM));
	SetValue(IDC_CHECK15, HasAlgorithm(m_Algorithms->Symmetric, Algorithm::Symmetric::CHACHA20_POLY1305));

	SetValue(IDC_CHECK14, HasAlgorithm(m_Algorithms->Compression, Algorithm::Compression::DEFLATE));
	SetValue(IDC_CHECK16, HasAlgorithm(m_Algorithms->Compression, Algorithm::Compression::ZSTANDARD));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CAlgorithmsDlg::OnBnClickedOk()
{
	QuantumGate::Algorithms algs;

	if (GetBoolValue(IDC_CHECK1)) algs.Hash.emplace(Algorithm::Hash::SHA256);
	if (GetBoolValue(IDC_CHECK2)) algs.Hash.emplace(Algorithm::Hash::SHA512);
	if (GetBoolValue(IDC_CHECK3)) algs.Hash.emplace(Algorithm::Hash::BLAKE2S256);
	if (GetBoolValue(IDC_CHECK4)) algs.Hash.emplace(Algorithm::Hash::BLAKE2B512);

	if (GetBoolValue(IDC_CHECK6)) algs.PrimaryAsymmetric.emplace(Algorithm::Asymmetric::ECDH_SECP521R1);
	if (GetBoolValue(IDC_CHECK7)) algs.PrimaryAsymmetric.emplace(Algorithm::Asymmetric::ECDH_X25519);
	if (GetBoolValue(IDC_CHECK8)) algs.PrimaryAsymmetric.emplace(Algorithm::Asymmetric::ECDH_X448);
	if (GetBoolValue(IDC_CHECK17)) algs.PrimaryAsymmetric.emplace(Algorithm::Asymmetric::KEM_CLASSIC_MCELIECE);
	if (GetBoolValue(IDC_CHECK19)) algs.PrimaryAsymmetric.emplace(Algorithm::Asymmetric::KEM_NTRUPRIME);
	if (GetBoolValue(IDC_CHECK21)) algs.PrimaryAsymmetric.emplace(Algorithm::Asymmetric::KEM_NEWHOPE);

	if (GetBoolValue(IDC_CHECK10)) algs.SecondaryAsymmetric.emplace(Algorithm::Asymmetric::ECDH_SECP521R1);
	if (GetBoolValue(IDC_CHECK11)) algs.SecondaryAsymmetric.emplace(Algorithm::Asymmetric::ECDH_X25519);
	if (GetBoolValue(IDC_CHECK12)) algs.SecondaryAsymmetric.emplace(Algorithm::Asymmetric::ECDH_X448);
	if (GetBoolValue(IDC_CHECK18)) algs.SecondaryAsymmetric.emplace(Algorithm::Asymmetric::KEM_CLASSIC_MCELIECE);
	if (GetBoolValue(IDC_CHECK20)) algs.SecondaryAsymmetric.emplace(Algorithm::Asymmetric::KEM_NTRUPRIME);
	if (GetBoolValue(IDC_CHECK22)) algs.SecondaryAsymmetric.emplace(Algorithm::Asymmetric::KEM_NEWHOPE);

	if (GetBoolValue(IDC_CHECK13)) algs.Symmetric.emplace(Algorithm::Symmetric::AES256_GCM);
	if (GetBoolValue(IDC_CHECK15)) algs.Symmetric.emplace(Algorithm::Symmetric::CHACHA20_POLY1305);

	if (GetBoolValue(IDC_CHECK14)) algs.Compression.emplace(Algorithm::Compression::DEFLATE);
	if (GetBoolValue(IDC_CHECK16)) algs.Compression.emplace(Algorithm::Compression::ZSTANDARD);

	*m_Algorithms = std::move(algs);

	CDialogBase::OnOK();
}

// This file is part of the QuantumGate project. For copyright and
// licensing information refer to the license file(s) in the project root.

#include "stdafx.h"
#include "TestApp.h"
#include "CSettingsDlg.h"

IMPLEMENT_DYNAMIC(CSettingsDlg, CDialogBase)

CSettingsDlg::CSettingsDlg(CWnd* pParent /*=nullptr*/) : CDialogBase(IDD_SETTINGS, pParent)
{}

CSettingsDlg::~CSettingsDlg()
{}

void CSettingsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogBase::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSettingsDlg, CDialogBase)
	ON_BN_CLICKED(IDOK, &CSettingsDlg::OnBnClickedOk)
END_MESSAGE_MAP()

BOOL CSettingsDlg::OnInitDialog()
{
	CDialogBase::OnInitDialog();

	assert(m_StartupParameters != nullptr);

	SetValue(IDC_IPV4LB, m_StartupParameters->Relays.IPv4ExcludedNetworksCIDRLeadingBits);
	SetValue(IDC_IPV6LB, m_StartupParameters->Relays.IPv6ExcludedNetworksCIDRLeadingBits);
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CSettingsDlg::OnBnClickedOk()
{
	m_StartupParameters->Relays.IPv4ExcludedNetworksCIDRLeadingBits = static_cast<UInt8>(GetUInt64Value(IDC_IPV4LB));
	m_StartupParameters->Relays.IPv6ExcludedNetworksCIDRLeadingBits = static_cast<UInt8>(GetUInt64Value(IDC_IPV6LB));

	CDialogBase::OnOK();
}
